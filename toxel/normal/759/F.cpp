#include <bits/stdc++.h>

const int moder = (int) 1e9 + 7;
const int inv2 = (moder + 1) / 2;
const int END = -1;
const int SYMBOL = 0;
const int NUMBER = 1;
const int N = 100010;
using ll = long long;

int powermod(int a, ll exp, int mod = moder){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % mod;
        }
        a = 1ll * a * a % mod;
    }
    return ret;
}

struct Number{
    int value, len;

    explicit Number(int value = 0, int len = 0):value(value), len(len){}

    Number contactenate(const Number &n)const{
        int nvalue = (1ll * value * powermod(10, n.len) + n.value) % moder;
        int nlen = len + n.len;
        nlen -= nlen >= moder - 1 ? moder - 1 : 0;
        return Number(nvalue, nlen);
    }
};

int type;
std::string token;
char s[N], *p;
Number dp[N];

void parseToken(){
    if (*p == '\0'){
        type = END;
        return;
    }
    token.clear();
    if (isdigit(*p)){
        type = NUMBER;
        while (isdigit(*p)){
            token.push_back(*(p ++));
        }
        return;
    }
    type = SYMBOL;
    token = *(p ++);
}

Number parseExpression();
Number parseTerm();
Number parseNumber(const std::string &, int);
Number calc(int, int, int, int, int);
Number parseRange(const std::string &, const std::string &);
Number parseRangeZero(const std::string &);

Number parseExpression(){
    Number number = parseTerm();
    if (type == END || (type == SYMBOL && token == ")")){
        return number;
    }
    parseToken();
    return number.contactenate(parseExpression());
}

Number parseTerm(){
    std::string num = token;
    parseToken();
    if (token == "-"){
        parseToken();
        std::string num1 = token;
        parseToken();
        return parseRange(num, num1);
    }
    if (token == "("){
        parseToken();
        Number number = parseExpression();
        int ratio = powermod(10, number.len);
        Number number1 = parseNumber(num, moder - 1);
        int nlen = 1ll * number.len * number1.value % (moder - 1);
        Number ret;
        if (ratio == 1){
            number1 = parseNumber(num, moder);
            int nvalue = 1ll * number.value * number1.value % moder;
            ret = Number(nvalue, nlen);
        }
        else{
            int inv = powermod(ratio - 1, moder - 2);
            int nvalue = 1ll * inv * (powermod(10, 1ll * number1.value * number.len) - 1) % moder * number.value % moder;
            nvalue += nvalue < 0 ? moder : 0;
            ret = Number(nvalue, nlen);
        }
        parseToken();
        return ret;
    }
    return parseNumber(num, moder);
}

Number parseNumber(const std::string &str, int mod){
    int remain = 0;
    for (auto ch : str){
        remain = (10ll * remain + ch - '0') % mod;
    }
    return Number(remain, str.size());
}

Number calc(int l, int r, int l1, int r1, int len){
    int coe = powermod(10, 1ll * len * r1);
    int ratio = powermod(10, (moder - 1) - len);
    Number ret;
    int nlen = 1ll * len * (r1 - l1 + 1) % (moder - 1);
    nlen += nlen < 0 ? moder - 1 : 0;
    if (ratio == 1){
        int ans = 1ll * (l + r) * (r - l + 1) % moder * inv2 % moder;
        ans += ans < 0 ? moder : 0;
        ret = Number(ans, nlen);
    }
    else{
        int ans = (1ll * l * powermod(ratio, l1) - 1ll * r * powermod(ratio, r1 + 1)) % moder;
        ans = (ans + 1ll * (powermod(ratio, r1 + 1) - powermod(ratio, l1 + 1)) * powermod(ratio - 1, moder - 2)) % moder;
        ans = 1ll * ans * powermod(1 - ratio, moder - 2) % moder;
        ans += ans < 0 ? moder : 0;
        ret = Number(ans, nlen);
    }
    ret.value = 1ll * ret.value * coe % moder;
    return ret;
}

Number parseRange(const std::string &l, const std::string &r){
    Number number_r = parseRangeZero(r);
    std::string nl = l;
    -- nl.back();
    for (int i = (int) nl.size() - 1; i > 0; -- i){
        if (nl[i] < '0'){
            nl[i] += 10;
            -- nl[i - 1];
        }
        else{
            break;
        }
    }
    if (nl[0] == '0'){
        nl = nl.substr(1, nl.size() - 1);
    }
    if (!nl.empty()){
        Number number_l = parseRangeZero(nl);
        int nvalue = (number_r.value - 1ll * number_l.value * powermod(10, number_r.len - number_l.len + moder - 1)) % moder;
        nvalue += nvalue < 0 ? moder : 0;
        int nlen = number_r.len - number_l.len;
        nlen += nlen < 0 ? moder - 1 : 0;
        number_r = Number(nvalue, nlen);
    }
    return number_r;
}

Number parseRangeZero(const std::string &str_r){
    int l = powermod(10, str_r.size() - 1);
    int l1 = powermod(10, str_r.size() - 1, moder - 1);
    int r = parseNumber(str_r, moder).value;
    int r1 = parseNumber(str_r, moder - 1).value;
    return dp[(int) str_r.size() - 1].contactenate(calc(l, r, l1, r1, str_r.size()));
}

int main(){
    for (int i = 1; i < N; ++ i){
        int l = powermod(10, i - 1);
        int r = powermod(10, i) - 1;
        r += r < 0 ? moder : 0;
        int l1 = powermod(10, i - 1, moder - 1);
        int r1 = powermod(10, i, moder - 1) - 1;
        r1 += r1 < 0 ? moder - 1 : 0;
        dp[i] = dp[i - 1].contactenate(calc(l, r, l1, r1, i));
    }
    scanf("%s", s);
    p = s;
    parseToken();
    printf("%d\n", parseExpression().value);
    return 0;
}