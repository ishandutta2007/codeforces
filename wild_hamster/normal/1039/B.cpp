#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000002015
typedef long long ll;
using namespace std;
ll n,m,k,x,y, sz, t;
ll a[200500], b[200500], c[200500];
string bullshit = "fdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmjfdsjkhsdkghjjhtgjerfgijmbjgijfdnibjndsiofmoeirgjeurghuiamfodkamdfksgjsdkfgkehrjktgherkghrunvujhsdfnvhabusfbasuydfbasmbfuigsbmuhgbnfgbvokdfsmbsinbiuseguiehguifsibmdsffbumiogusmsfdiogmj";
int main()
{
    //freopen("input.txt", "r", stdin);
    int hsh = 0;
    for (int i = 0; i < bullshit.size(); i++)
        hsh = (1LL*hsh*27+bullshit[i]-'0')%MOD;
    srand(hsh);
    double prob = 1;
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = n;
    for (int i = 0; i < 4500; i++) {
        if (r-l < 50) {
            ll diff = r-l+1;
            ll rand_val = rand()%diff;
            ll cur = l+rand_val;
            cout << cur << " " << cur << endl;
            fflush(stdout);
            string ans;
            cin >> ans;
            //ans = "No";
            //prob = prob*1.*(diff-1)/diff;
            if (ans == "Yes") {
                return 0;
            }
            l = max(l-k, 1LL);
            r = min(r+k, n);
        } else {
            ll mid = (l+r)/2;
            cout << l << " " << mid << endl;
            fflush(stdout);
            string ans;
            cin >> ans;
            //ans = rand()%2?"Yes":"No";
            if (ans == "Yes") {
                l = max(l-k, 1LL);
                r = min(mid+k, n);
            } else {
                l = max(mid+1-k, 1LL);
                r = min(r+k, n);
            }
        }
    }
    //cout << prob << endl;
	return 0;
}