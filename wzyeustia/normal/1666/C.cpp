#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0) {putchar('-');x=-x;}    if(x>=10)   write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

pair<int,int> p[5];

int main(){
	For(i, 1, 3) p[i].fir = read(), p[i].sec = read();
	sort(p + 1, p + 4);
	int miy = min(p[1].sec, min(p[2].sec, p[3].sec));
	int mxy = max(p[1].sec, max(p[2].sec, p[3].sec));
	puts("3");
	write_p(p[2].fir); write_p(miy); write_p(p[2].fir); writeln(mxy);
	write_p(p[2].fir); write_p(p[1].sec); write_p(p[1].fir); writeln(p[1].sec);
	write_p(p[2].fir); write_p(p[3].sec); write_p(p[3].fir); writeln(p[3].sec);
}