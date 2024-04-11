#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
char s[100055];
inline bool G(char x)
{
    return x=='A'||x=='H'||x=='I'||x=='M'||x=='O'||x=='T'||x=='U'||x=='V'||x=='W'||x=='X'||x=='Y';
}
int main() 
{
    gets(s);
    for(int l=0,r=strlen(s)-1;l<=r;l++,r--)
    {
        if((!G(s[l]))||s[l]!=s[r]){puts("NO");return 0;}
    }
    puts("YES");
    return 0;
}