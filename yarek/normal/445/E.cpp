//no chuj ;_;
//w 85 linijce zamiast "a1" byo "a", to by bug
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<tr1/unordered_map>
#include<queue>
#include<cstdlib>
#include<list>
#include<set>
#include<map>
#include<cstring>
#define MP make_pair
#define PB push_back
#define s second
#define f first
#define PII pair<int,int>
#define VPII vector <pair<int,int> >
#define VI vector <int>
#define abs(a) max((a),-(a))
typedef long long LL;
#define LD long double
#define ALL(x) x.begin(),x.end()
#define PU putchar_unlocked
#define GU getchar_unlocked
#define DBG(x) cerr<<#x<<" "<<(x)<<endl;
using namespace std;
int a,b,c,e,f,n,m,mx,l,z,r,k,x;
int INF=1e9+1;

void insert(int a, int b, LL x);
LL query(int a, int b);


set <pair< PII , int> > S;
set <pair< PII , int> >::iterator it,it2;
void add(int a,int b,int x)
{
it=S.upper_bound(MP(MP(a,1e9),-1));
it--;
if(it->f.f<a&&b<it->f.s)
    {
    insert(a,b,abs(it->s-x));
    int a1,a2,a3;
    a1=it->f.f;
    a2=it->f.s;
    a3=it->s;
    S.erase(it);
    
    S.insert(MP(MP(a1,a-1),a3));
    S.insert(MP(MP(a,b),x));
    S.insert(MP(MP(b+1,a2),a3));
    return;
    }

while(1)
    {
    it=S.upper_bound(MP(MP(a,1e9),-1));
    it--;
    if(it->f.s<a)it++;
    if(b<it->f.f)break;
    if(it->f.f<a)
        {
        int a1,a2,a3;
        a1=it->f.f;
        a2=it->f.s;
        a3=it->s;
//      printf("%d %d %d\n",a1,a2,a3);
        S.erase(it);
    
        insert(a,a2,abs(a3-x));
    
        S.insert(MP(MP(a1,a-1),a3));
        
        continue;
        }
    if(b<it->f.s)
        {
        int a1,a2,a3;
        a1=it->f.f;
        a2=it->f.s;
        a3=it->s;
        S.erase(it);
        
        insert(a1,b,abs(a3-x));
        
        S.insert(MP(MP(b+1,a2),a3));
        break;
        }
    insert(it->f.f,it->f.s,abs(it->s-x));
    S.erase(it);//puts("D");
    }
S.insert(MP(MP(a,b),x));

}

void solve()
{
scanf("%d%d",&n,&m);
for(int i=0;i<=n+1;i++)S.insert(MP(MP(i,i),i));
for(int i=1;i<=m;i++)
    {
    scanf("%d",&a); 
    if(a==1)
        {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        }   
    else
        {
        scanf("%d%d",&a,&b);
        cout<<query(a,b)<<endl;
        }
    }
}
main()
{
solve();
}


const int czapa=131072;
struct wezel{
    LL dod_przed;
    LL akt_wyn; 
    wezel(LL _a = 0, LL _b = 0): 
        dod_przed(_a), akt_wyn(_b) {};
};

wezel d[2*czapa];

LL rek_zejscie(int polewej, int w, int l, int p, int rodzaj, LL val, int rozmiar) {
    if (polewej == l && p-l+1 == rozmiar)
        d[w].dod_przed += LL(rodzaj)*val;

    if (rozmiar != 1) {
        d[2*w].dod_przed += d[w].dod_przed;
        d[2*w+1].dod_przed += d[w].dod_przed;
        d[w].dod_przed = 0;
    }
    else return d[w].dod_przed;
    
    if (polewej == l && p-l+1 == rozmiar) {
        d[w].akt_wyn = d[2*w].akt_wyn + d[2*w+1].akt_wyn + d[2*w].dod_przed*(rozmiar/2) + d[2*w+1].dod_przed*(rozmiar/2);
        return d[w].akt_wyn;
    }
    
    LL res = 0;
    if (polewej + rozmiar/2  > l) 
        res += rek_zejscie(polewej,w*2,l,min(p,polewej + rozmiar/2 - 1),rodzaj,val,rozmiar/2);
    if (polewej + rozmiar/2  <= p) 
        res += rek_zejscie(polewej + rozmiar/2,w*2+1,max(l,polewej + rozmiar/2),p,rodzaj,val,rozmiar/2);
    
    d[w].akt_wyn = d[2*w].akt_wyn + d[2*w+1].akt_wyn + d[2*w].dod_przed*(rozmiar/2) + d[2*w+1].dod_przed*(rozmiar/2);
    return res;
}

void insert(int a, int b, LL x) {
    rek_zejscie(0,1,a,b,1,x,czapa);
}

LL query(int a, int b) {
    return rek_zejscie(0,1,a,b,0,0,czapa);
}




/*

void insert(int a,int b,int c)
{
printf("%d %d\n",a,b);

}
LL query(int a,int b){return 0;}

*/