#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,a;
        cin>>s>>a;
        int k=(int)s.length(),n=(int)a.length();
        sort(s.begin(),s.end());
        string l="";
        for(int i=0;i<k;i++)l+=a[i];
        bool ok=0;
        string f=l;
        sort(f.begin(),f.end());
        if(f==s)ok=1;
        for(int i=k;i<n;i++){
            string g=l;
            sort(g.begin(),g.end());
            if(g==s)ok=1;
            string h="";
            for(int j=1;j<(int)l.length();j++){
                h+=l[j];
            }
            h+=a[i];
            string y=h;
            sort(h.begin(),h.end());
            l=y;
            if(h==s)ok=1;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}