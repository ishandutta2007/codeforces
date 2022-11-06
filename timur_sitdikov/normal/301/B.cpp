#include <iostream>
#include <vector>
using namespace std;

const int kInfinity = 1e8;

void ReadInputData(
  vector<int> &x, vector<int> &y, vector<int> &extra_time, int &coefficient) {
  int n;
  cin >> n >> coefficient;
  x.resize(n);
  y.resize(n);
  extra_time.resize(n);
  for(int i = 1; i < n - 1; i++) {
    cin >> extra_time[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
}

int GetDistance(
  const vector<int> &x, const vector<int> &y, const vector<int> &extra_time,
  int from, int to, int coefficient){
  return (abs(x[to] - x[from]) + abs(y[to] - y[from])) * coefficient - extra_time[from];
}

int GetMinCost(
    const vector<int> &x, const vector<int> &y,
    const vector<int> &extra_time, int coefficient) {
  int n = x.size();
  vector<bool> calculated(n);
  vector<int> distance(n, kInfinity);
  distance[n - 1] = 0;
  for(int i = 0; i < n; i++){
    int closest_vertex = -1, closest_distance = kInfinity;
    for(int j = 0; j < n; j++){
      if (!calculated[j] && distance[j] < closest_distance){
        closest_distance = distance[j];
        closest_vertex = j;
      }
    }
    calculated[closest_vertex] = true;
    for(int j = 0; j < n; j++) {
      if (!calculated[j]) {
        distance[j] = min(distance[j], max(0, closest_distance + GetDistance(x, y, extra_time, closest_vertex, j, coefficient)));
      }
    }
  }
  return distance[0];
}

// To execute C++, please define "int main()"
int main() {
  vector<int> x, y, extra_time;
  int coefficient;
  ReadInputData(x, y, extra_time, coefficient);
  cout << GetMinCost(x, y, extra_time, coefficient) << endl;
  return 0;
}