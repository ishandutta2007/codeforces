#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int INF=555;
string s;
int lst[26],kk[26];
int d[4]={0,2,5,7},f[4]={0,5,0,5};
int ans=INF;
void init(){
    for(int i=0;i<26;i++)lst[i]=-1,kk[i]=0;
    for(int i=0;i<(int)s.length();i++){
        int c=(int)s[i]-'0';
        lst[c]=max(lst[c],i);
        kk[c]++;
    }
}
int main(){
    cin>>s;
    int n=(int)s.length();
    init();
    bool ok=0;
    for(int i=0;i<4;i++){
        if(lst[f[i]]==-1||lst[d[i]]==-1||(i==0&&kk[i]<2))continue;
        string ns=s;
        int cnt=0;
        for(int j=lst[f[i]];j<n-1;j++){swap(ns[j],ns[j+1]);cnt++;}
        int tt[26];
        for(int j=0;j<26;j++)tt[j]=-1;
        for(int j=0;j<n-1;j++)tt[(int)(ns[j]-'0')]=j;
        for(int j=tt[d[i]];j<n-2;j++){swap(ns[j],ns[j+1]);cnt++;}
        if(ns[0]=='0'){
            int dgt=-1;
            for(int j=0;j<n-2;j++){
                if(ns[j]!='0'){
                    dgt=j;
                    break;
                }
            }
            cnt+=dgt;
            for(int i=dgt;i>0;i--)swap(ns[i],ns[i-1]);
        }
        if(ns[0]!='0')ans=min(ans,cnt),ok=1;
        cerr << ns << "  :" << cnt << endl;
    }
    if(ok)printf("%i",ans);
    else printf("-1");
    return 0;
}

//574196831896431419