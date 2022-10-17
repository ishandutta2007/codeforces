#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int ans[] = {0,13439,106064,189279,106064,330095,388944,106064,106064,189279,560720,486464,388944,263744,106064,670095,106064};

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            int x;
            cin>>x;
            if((i+j)&1) cout<<ans[x]<<" ";
            else cout<<720720<<" ";
        }
        cout<<endl;
    }
}