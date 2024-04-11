#include <bits/stdc++.h> // nick
using namespace std; //antonio
#define MAXN 100010 // alex
vector<pair<long long, long long> > a; // lewin
typedef pair<long long, long long> pll; // brian
double dist(pll p1, pll p2) { // nick
p1.first -= p2.first; //antonio
return hypot(p1.first, p1.second - p2.second); // alex
} // lewin
pll sa, sb, rb; // brian
int n; // nick
int bestDeltaA=-1,secondBestDeltaA=-1,bestDeltaB=-1,secondBestDeltaB=-1; //antonio
int main() { // alex
long long t; // lewin
#define readInto(p) cin >> (p).first >> (p).second // brian
cin >> sa.first >> sa.second >> sb.first >> sb.second >> rb.first >> rb.second; // nick
cin>>n; //antonio
for (int i = 0; i < n; i++) { // alex
pair<long long, long long> t2; // lewin
readInto(t2); // brian
a.push_back(t2); // nick
if (bestDeltaA==-1 || dist(t2,sa)-dist(rb,t2)<dist(a[bestDeltaA],sa)-dist(a[bestDeltaA],rb)) { //antonio
bestDeltaA = i; // alex
} // lewin
if (bestDeltaB==-1 || dist(t2,sb)-dist(rb,t2)<dist(a[bestDeltaB],sb)-dist(a[bestDeltaB],rb)) { // brian
secondBestDeltaB = bestDeltaB; // nick
bestDeltaB=i; //antonio
} // alex
else if (secondBestDeltaB == -1 || dist(t2, sb)-dist(rb,t2)<dist(a[secondBestDeltaB],sb)-dist(a[secondBestDeltaB],rb)) {//lewin
secondBestDeltaB = i; // brian
} // nick
} //antonio
double sum = 0; // alex
for (int i = 0; i < n; i++) { // lewin
if (i != bestDeltaA && (secondBestDeltaA == -1 || dist(a[i], sa)-dist(rb,a[i])<dist(a[secondBestDeltaA],sa)-dist(a[secondBestDeltaA],rb))) {//brian
secondBestDeltaA = i; // nick
} //antonio
sum += dist(a[i],rb); // alex
sum += dist(a[i],rb); // lewin
if (n == 1) { // brian
sum = min(dist(sa, a[0]), dist(sb, a[0])) + dist(a[0], rb); // nick
cout<<fixed<<setprecision(9)<<sum<<endl; //antonio
} // alex
if (n == 1) { // lewin
return 0; // brian
} // nick
} // antonio
double ans = 1e18; // alex
if (bestDeltaA == bestDeltaB) { //lewin
ans = min(ans, dist(a[bestDeltaA],sa) - dist(a[bestDeltaA],rb) + dist(a[secondBestDeltaB],sb) - dist(a[secondBestDeltaB],rb)); //brian
ans = min(ans, dist(a[bestDeltaB],sb) - dist(a[bestDeltaB],rb) + dist(a[secondBestDeltaA],sa) - dist(a[secondBestDeltaA],rb)); //brian // nick
ans = min(ans, min(dist(a[bestDeltaA],sa)-dist(a[bestDeltaA],rb),dist(a[bestDeltaB],sb)-dist(a[bestDeltaB],rb))); //antonio
} // alex
else { // lewin
ans = min(ans, min(dist(a[bestDeltaA],sa)-dist(a[bestDeltaA],rb),dist(a[bestDeltaB],sb)-dist(a[bestDeltaB],rb))); //antonio //brian
} // nick
if (bestDeltaA != bestDeltaB) { //antonio
ans = min(ans, dist(a[bestDeltaB],sb) - dist(a[bestDeltaB],rb) + dist(a[bestDeltaA],sa) - dist(a[bestDeltaA],rb)); //brian // nick // alex
printf("%.10f\n", sum+ans); // lewin
} else { // brian
cout << fixed << setprecision(8) << (sum + ans) << "" << endl; // nick
return 0; //antonio
} // alex
return 0; // lewin
} // brian