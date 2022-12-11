#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

#define X first
#define Y second

const string dict[6]={"S", "M", "L", "XL", "XXL", "XXXL"};

vector <ii> v[6];

int n,a[6],h[100005];
int convert(string s){
    int ans=0;
    while (s!=dict[ans]) ans++;
    return ans;
}
int main(){
    for(int i=0;i<6;i++) cin>>a[i];
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        vector <int> gr;
        for(int en=0;en<s.length();en++) if (s[en]!=','){
            int st=en;
            while (en<s.length()&&s[en]!=',') en++;
//            cout<<i<<" "<<s.substr(st,en-st)<<'\n';
            gr.push_back(convert(s.substr(st,en-st)));
        }
        int n1=gr.size();
        sort(gr.begin(),gr.end());
//        for(int j=0;j<n1;j++) cout<<i<<" "<<gr[j]<<'\n';
        for(int j=0;j<n1;j++) v[gr[j]].push_back(ii(n1-j-1,i));
    }
    for(int i=0;i<6;i++) sort(v[i].begin(),v[i].end());
    for(int i=0;i<6;i++)
        for(auto j:v[i]) if (!h[j.Y]){
//            cout<<i<<" "<<j.X<<" "<<j.Y<<'\n';
            if (!a[i]){
                if (j.X==0) {
                    printf("NO");
                    return 0;
                }
            }else{
                    h[j.Y]=i+1;
                    a[i]--;
            }
        }
    printf("YES\n");
    for(int i=1;i<=n;i++) cout<<dict[h[i]-1]<<'\n';
}