#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;

int counts[26];
ii counts2[26];
int n,k;

long long sq(long long a) {
return a*a;
}

int main() {

  cin >> n >> k;
  char let;
  for (int i = 0; i<n; i++) {
    cin >> let;
    counts[let-'A']++;
  }

for (int i = 0; i<26; i++)
counts2[i]=make_pair(counts[i],i);

sort(counts2,counts2+26,greater< ii >());
long long score=0;
int i = 0;
while (k) {
score+=sq(min(counts2[i].first,k));
//cout << char(counts2[i].second+'A') << endl;
k-=min(counts2[i].first,k);
i++;
}

cout << score << endl;

  return 0;
}