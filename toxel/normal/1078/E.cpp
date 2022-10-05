#include<bits/stdc++.h>

const int BIT = 31;
const int N = 35;
const int M = 7;

char s[M << 1][N << 1];
int x = M, y = N;

struct op{
    int x, y, value;
};

std::vector <op> vec;

void display(){
    for (int i = 0; i < M << 1; ++ i){
        printf("%s\n", s[i]);
    }
}

void print(const char *s){
    const char *tmp = s;
    while (*s != '\0'){
        if (*s == 't'){
            int num = ::s[x][y] == ' ' ? 0 : ::s[x][y] - '0' + 1;
            for (int i = 0; i < num; ++ i){
                if (vec.empty()) break;
                x = vec.back().x;
                y = vec.back().y;
                ::s[x][y] = vec.back().value;
                vec.pop_back();
            }
        }
        else{
            vec.push_back({x, y, ::s[x][y]});
            switch (*s){
                case 'u' : -- x; break;
                case 'd' : ++ x; break;
                case 'r' : ++ y; break;
                case 'l' : -- y; break;
                case '0' : ::s[x][y] = '0'; break;
                case '1' : ::s[x][y] = '1'; break;
            }
        }
        ++ s;
    }
    printf("%s", tmp);
}

void move(char dir, bool inv = false){
    char neg = dir == 'u' ? 'd' : dir == 'd' ? 'u' : dir == 'l' ? 'r' : 'l';
    char tmp[100];
    sprintf(tmp, "%c%d%d%ct", dir, (int) !inv, (int) inv, neg);
    print(tmp);
}

void AND(){
    move('r');
    print("ld");
    move('r');
    print("u0dt");
}

void OR(){
    move('r', true);
    print("ld");
    move('r', true);
    print("u");
    AND();
    move('l', true);
}

void XOR(){
    move('r', true);
    print("ld");
    move('r');
    print("u");
    AND();
    move('u');
    print("lld");
    move('r');
    print("ld");
    move('r', true);
    print("u");
    AND();
    print("u");
    OR();
    move('l');
    move('l');
    move('d');
}

int main(){
    for (int i = 0; i < M << 1; ++ i){
        for (int j = 0; j < (N << 1) - 1; ++ j){
            s[i][j] = ' ';
        }
    }
    int test;
    scanf("%d", &test);
    int a, b;
    while (test --){
        scanf("%d%d", &a, &b);
    }
    for (int i = 0; a; -- i){
        s[0 + M][i + N] = '0' + (a & 1);
        a >>= 1;
    }
    for (int i = 0; b; -- i){
        s[-1 + M][i + N] = '0' + (b & 1);
        b >>= 1;
    }
    print("u");
    for (int i = 0; i < BIT; ++ i){
        print("uu0u1dd10dtuut");
        move('d');
        print("l");
    }
    for (int i = 0; i < BIT; ++ i){
        print("r");
    }
    print("d");
    for (int i = 0; i < BIT; ++ i){
        print("dd0d1uu10utddt");
        move('u');
        print("l");
    }
    for (int i = 0; i <= BIT; ++ i){
        print("r");
    }
    print("u0l");
    for (int i = 0; i < BIT; ++ i){
        move('u');
        for (int j = 0; j <= i; ++ j){
            move('r');
        }
        for (int j = 0; j <= i; ++ j){
            print("l");
        }
        print("dd");
        move('d');
        for (int j = 0; j <= i; ++ j){
            move('r');
        }
        move('u');
        print("u");
        XOR();
        print("ul");
        move('r');
        XOR();
        move('u');
        for (int j = 0; j < 3; ++ j){
            move('l');
        }
        move('d');
        for (int j = 0; j < i; ++ j){
            move('l');
        }
        move('d');
        for (int j = 0; j <= i; ++ j){
            print("r");
        }
        print("d");
        move('r');
        for (int j = 0; j < 3; ++ j){
            move('u');
        }
        move('l');
        AND();
        print("dl");
        AND();
        print("dl");
        AND();
        print("u");
        OR();
        print("ul");
        move('r');
        OR();
        for (int j = 0; j < 3; ++ j){
            move('l');
        }
        move('d');
        move('d');
        if (i == BIT - 1){
            putchar('e');
        }
        for (int j = 0; j <= i + 1; ++ j){
            print("l");
        }
        if (i == BIT - 1){
            putchar('r');
        }
    }
    puts("");
    return 0;
}