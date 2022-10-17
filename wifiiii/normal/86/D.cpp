
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

namespace IO {
    const int BUFFER_SIZE = 1 << 15;
    
    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;
    
    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;
    
    uint8_t lookup[100];
    
    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
    }
    
    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();
        
        return input_buffer[advance ? input_pos++ : input_pos];
    }
    
    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
    }
    
    template<typename T>
    inline void read(T &number) {
        while (isspace(next_char(false)))
            next_char();
        
        bool negative = next_char(false) == '-';
        
        if (negative)
            next_char();
        
        number = 0;
        
        while (isdigit(next_char(false)))
            number = 10 * number + (next_char() - '0');
        
        if (negative)
            number = -number;
    }
    
    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }
    
    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();
        
        output_buffer[output_pos++] = c;
    }
    
    template<typename T>
    inline void write_int(T number, char after = 0) {
        if (number < 0) {
            write_char('-');
            number = -number;
        }
        
        static char number_buffer[100];
        int length = 0;
        
        do {
            if (number < 10) {
                number_buffer[length++] = number + '0';
                number = 0;
            } else {
                uint8_t lookup_value = lookup[number % 100];
                number /= 100;
                number_buffer[length++] = (lookup_value & 15) + '0';
                number_buffer[length++] = (lookup_value >> 4) + '0';
            }
        } while (number != 0);
        
        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);
        
        if (after)
            write_char(after);
    }
    
    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);
        
        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}

const int maxn = 1e6+6;
struct Ask
{
    int id,l,r;
    ll ans;
}ask[maxn];
int a[maxn];
ll cnt[maxn];
ll ans = 0;
int blo;
bool cmp(Ask a1,Ask a2)
{
    return a1.r/blo < a2.r/blo || (a1.r/blo==a2.r/blo&&a1.l<a2.l);
}
int l=1,r;
inline void add(ll x)
{
    ans += x * (2 * cnt[x] + 1);
    ++cnt[x];
}
inline void del(ll x)
{
    ans += x * (-2*cnt[x] + 1);
    --cnt[x];
}
inline int read()
{
    char c=getchar();int x=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x;
}
using namespace IO;
int32_t main()
{
    IO::init();
    int n,m;
    read(n),read(m);
    rep(i,n) read(a[i]);
    blo = pow(n,0.5);
    if(!blo) blo=1;
    rep(i,m)
    {
        read(ask[i].l),read(ask[i].r);
        ask[i].id = i;
    }
    sort(ask+1,ask+1+m,cmp);
    rep(i,m)
    {
        while(l<ask[i].l) del(a[l++]);
        while(l>ask[i].l) add(a[--l]);
        while(r<ask[i].r) add(a[++r]);
        while(r>ask[i].r) del(a[r--]);
        ask[ask[i].id].ans = ans;
    }
    rep(i,m) write_int(ask[i].ans,'\n');
}