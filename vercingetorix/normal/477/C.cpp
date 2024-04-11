#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

/*int xmin[2000][500];
int xmax[2000][500];
int num[2000][500];*/
int mindels[2][2001];
string s,p;

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    
    int n,m;
    int syms = 0;
    cin>>s;
    cin>>p;
    int cursym=0;
    vi ans(s.size()+1);
    for(int i=0; i<s.size(); i++){
        if(s[i]==p[cursym]){
            syms++;
            cursym++;
            if(cursym==p.size()) cursym=0;
        }
    }
    int maxans=syms/p.size();
   /* int nextsym=0;
    int psize=p.size();
    for(int i=0; i<s.size();i++){
        for(int j=0; j<p.size(); j++){
            xmin[i][j]=0;
            xmax[i][j]=0;
            num[i][j]=-1;
        }
    }
    num[0][0]=0;
    for(int i=0; i<s.size();i++){
        char c=s[i];
        for(int j=0; j<nextsym; j++){
            if(c==p[j]){
                int numadd=0;
                int newsym=j+1;
                if(newsym>=psize){ newsym=0; numadd++; }
                if(i>0) numadd=num[i-1][j];
                int numwas=num[i-1][newsym];
                if(numwas>numadd){
                    xmin[i][newsym]=xmin[i-1][newsym];
                }
                else if(numadd>numwas){
                    
                }
                else{
                    
                }
            }
        }
    }*/
    //cout<<maxans;
    for(int i=0; i<=maxans*p.size(); i++){
        ans[s.size()-i]=i/p.size();
        mindels[0][i]=s.size();
        mindels[1][i]=s.size();
    }
    //for(int i=0; i<=s.size(); i++) cout<<ans[i]<<" "; cout<<endl;
    mindels[0][0]=0;
    mindels[1][0]=0;
    int maxlen=maxans*p.size();
    int maxpos=0;
    for(int i=0; i<s.size(); i++){
        int ii=i%2;
        int i1=1-ii;
        if((maxpos<maxlen)&&(s[i]==p[maxpos%p.size()])) maxpos++;
        for(int j=1; j<=maxpos; j++){
            //compute mindels[ii][j]
            int newd=mindels[i1][j];
            int lastsym=(j+p.size()-1)%p.size();
            if(lastsym!=p.size()-1) newd++;
            if(s[i]==p[lastsym]) newd=std::min(newd, mindels[i1][j-1]);
            //cout<<newd<<" WTF "<<mindels[i1][j-1]<<endl;
            mindels[ii][j]=newd;
        }
    }
    int cnt=0;
    //for(int i=0; i<=s.size(); i++) cout<<ans[i]<<" "; cout<<endl;
    for(int i=1; i<=maxans; i++){
        while(cnt<mindels[(s.size()+1)%2][i*p.size()]){
            ans[cnt]=i-1;
            cnt++;
        }
    }
    for(int i=mindels[(s.size()+1)%2][maxlen]; i<s.size()-maxlen; i++) ans[i]=maxans;
    /*for(int i=0; i<s.size()-maxlen;i++){
        int a=0;
        for(int j=1; j<=maxans; j++) if(mindels[(s.size()+1)%2][i*p.size()]<=i) a=j;
        ans[i]=a;
    }*/
    for(int i=0; i<=s.size(); i++) cout<<ans[i]<<" ";
}