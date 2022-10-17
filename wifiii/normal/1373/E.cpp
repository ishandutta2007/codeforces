#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 1000005;
int a[maxn],s[maxn];
int f(int x) {
    int ret=0;
    while(x) ret+=x%10,x/=10;
    return ret;
}
int ans[155][15];
int main() {
    ans[1][1]=0,ans[2][1]=-1,ans[3][1]=1,ans[4][1]=-1,ans[5][1]=2,ans[6][1]=-1,ans[7][1]=3,ans[8][1]=-1,ans[9][1]=4,ans[10][1]=9,ans[11][1]=5,ans[12][1]=19,ans[13][1]=6,ans[14][1]=29,ans[15][1]=7,ans[16][1]=39,ans[17][1]=8,ans[18][1]=49,ans[19][1]=18,ans[20][1]=59,ans[21][1]=28,ans[22][1]=69,ans[23][1]=38,ans[24][1]=79,ans[25][1]=48,ans[26][1]=89,ans[27][1]=58,ans[28][1]=189,ans[29][1]=68,ans[30][1]=289,ans[31][1]=78,ans[32][1]=389,ans[33][1]=88,ans[34][1]=489,ans[35][1]=98,ans[36][1]=589,ans[37][1]=198,ans[38][1]=689,ans[39][1]=298,ans[40][1]=789,ans[41][1]=398,ans[42][1]=889,ans[43][1]=498,ans[44][1]=989,ans[45][1]=598,ans[46][1]=1989,ans[47][1]=698,ans[48][1]=2989,ans[49][1]=798,ans[50][1]=3989,ans[51][1]=898,ans[52][1]=4989,ans[53][1]=998,ans[54][1]=5989,ans[55][1]=1998,ans[56][1]=6989,ans[57][1]=2998,ans[58][1]=7989,ans[59][1]=3998,ans[60][1]=8989,ans[61][1]=4998,ans[62][1]=9989,ans[63][1]=5998,ans[64][1]=19989,ans[65][1]=6998,ans[66][1]=29989,ans[67][1]=7998,ans[68][1]=39989,ans[69][1]=8998,ans[70][1]=49989,ans[71][1]=9998,ans[72][1]=59989,ans[73][1]=19998,ans[74][1]=69989,ans[75][1]=29998,ans[76][1]=79989,ans[77][1]=39998,ans[78][1]=89989,ans[79][1]=49998,ans[80][1]=99989,ans[81][1]=59998,ans[82][1]=199989,ans[83][1]=69998,ans[84][1]=299989,ans[85][1]=79998,ans[86][1]=399989,ans[87][1]=89998,ans[88][1]=499989,ans[89][1]=99998,ans[90][1]=599989,ans[91][1]=199998,ans[92][1]=699989,ans[93][1]=299998,ans[94][1]=799989,ans[95][1]=399998,ans[96][1]=899989,ans[97][1]=499998,ans[98][1]=999989,ans[99][1]=599998,ans[100][1]=1999989,ans[101][1]=699998,ans[102][1]=2999989,ans[103][1]=799998,ans[104][1]=3999989,ans[105][1]=899998,ans[106][1]=4999989,ans[107][1]=999998,ans[108][1]=5999989,ans[109][1]=1999998,ans[110][1]=6999989,ans[111][1]=2999998,ans[112][1]=7999989,ans[113][1]=3999998,ans[114][1]=8999989,ans[115][1]=4999998,ans[116][1]=9999989,ans[117][1]=5999998,ans[118][1]=19999989,ans[119][1]=6999998,ans[120][1]=29999989,ans[121][1]=7999998,ans[122][1]=39999989,ans[123][1]=8999998,ans[124][1]=49999989,ans[125][1]=9999998,ans[126][1]=59999989,ans[127][1]=19999998,ans[128][1]=69999989,ans[129][1]=29999998,ans[130][1]=79999989,ans[131][1]=39999998,ans[132][1]=89999989,ans[133][1]=49999998,ans[134][1]=99999989,ans[135][1]=59999998,ans[136][1]=199999989,ans[137][1]=69999998,ans[138][1]=299999989,ans[139][1]=79999998,ans[140][1]=399999989,ans[141][1]=89999998,ans[142][1]=499999989,ans[143][1]=99999998,ans[144][1]=599999989,ans[145][1]=199999998,ans[146][1]=699999989,ans[147][1]=299999998,ans[148][1]=799999989,ans[149][1]=399999998,ans[150][1]=899999989;
    int t;
    cin>>t;
    for(int i=1;i<maxn;++i) a[i]=a[i/10]+i%10,s[i]=s[i-1]+a[i];
    while(t--) {
        int n,k;
        cin>>n>>k;
        if(k==0) {
            int len=(n+8)/9;
            string s;
            for(int i=0;i<len;++i) {
                for(int j=1;j<=9;++j) {
                    if((len-1-i)*9>=n-j) {
                        s+=to_string(j);
                        n-=j;
                        break;
                    }
                }
            }
            cout<<s<<endl;
        } else if(k==1) {
            cout<<ans[n][1]<<endl;
        } else {
            ++k;
            if(s[k-1]==n) cout<<0<<endl;
            else {
                int ok=0;
                for(int i=k;i<maxn;++i) {
                    if(s[i]-s[i-k]==n) {
                        ok=1;
                        cout<<i-k+1<<endl;
                        break;
                    }
                }
                if(!ok) cout<<-1<<endl;
            }

        }
    }
}

//