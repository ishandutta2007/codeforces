#include <iostream>
#include <vector>

class BoatProblemSolver {
 public:
  void ReadData() {
    int n;
    std::cin >> n >> boat_capacity_;
    heavy_count_ = light_count_ = 0;
    for(int i = 0; i < n; i++) {
      int weight;
      std::cin >> weight;
      if (weight == kHeavyWeight) {
        heavy_count_++;
      } else if (weight == kLightWeight) {
        light_count_++;
      } else {
        throw("Invalid weight");
      }
    }
  }

  std::pair<int, int64_t> SolveBoatProblem() {
    if (!SolutionExists()) {
      return {-1, 0};
    }
    std::vector<std::vector<int64_t>> binomials = CalculateBinomials();
    std::vector<std::vector<int64_t>> boat_problem_has_solution;
    std::vector<std::vector<int64_t>> boat_problem_solution_count;
    std::vector<std::vector<int64_t>> previous_boat_problem_solution_count;
    boat_problem_has_solution.resize(heavy_count_ + 1);
    boat_problem_solution_count.resize(heavy_count_ + 1);
    previous_boat_problem_solution_count.resize(heavy_count_ + 1);
    for(size_t i = 0; i < boat_problem_solution_count.size(); i++){
      boat_problem_has_solution[i].resize(light_count_ + 1);
      boat_problem_solution_count[i].resize(light_count_ + 1);
      previous_boat_problem_solution_count[i].resize(light_count_ + 1);
    }
    boat_problem_has_solution[0][0] = true;
    boat_problem_solution_count[0][0] = 1;
    int number_of_boat_trips = 0;
    while(true) {
      if (boat_problem_has_solution[heavy_count_][light_count_]) {
        break;
      }
      number_of_boat_trips++;
      bool is_move_back = (number_of_boat_trips % 2 == 0);
      for(int i = 0; i <= heavy_count_; i++){
        for(int j = 0; j <= light_count_; j++) {
          previous_boat_problem_solution_count[i][j] = boat_problem_solution_count[i][j];
          boat_problem_solution_count[i][j] = 0;
        }
      }
      for(int i = 0; i <= heavy_count_; i++){
        int heavy_left = (is_move_back ? i : heavy_count_ - i);
        for(int j = 0; j <= light_count_; j++) {
          int light_left = (is_move_back ? j : light_count_ - j);
          if (!previous_boat_problem_solution_count[i][j]) {
            continue;
          }
          for(int k = 0; k <= heavy_left && k * kHeavyWeight <= boat_capacity_; k++){
            int total_heavy_moved = (is_move_back ? i - k : i + k);
            int64_t heavy_moved_count = binomials[heavy_left][k];
            for(int l = 0; l <= light_left && k * kHeavyWeight + l * kLightWeight <= boat_capacity_; l++) {
              if (k == 0 && l == 0){
                continue;
              }
              int total_light_moved = (is_move_back ? j - l : j + l);
              int64_t light_moved_count = binomials[light_left][l];
              boat_problem_has_solution[total_heavy_moved][total_light_moved] = true;
              int64_t coefficient = heavy_moved_count * light_moved_count % kModulo;
              boat_problem_solution_count[total_heavy_moved][total_light_moved] += (
                previous_boat_problem_solution_count[i][j] * coefficient);
              boat_problem_solution_count[total_heavy_moved][total_light_moved] %= kModulo;
              // std::cout << number_of_boat_trips << " " << i << " " << j << " " << total_heavy_moved << " " << total_light_moved << std::endl;
            }
          }
        }
      }
    }
    return {number_of_boat_trips, boat_problem_solution_count[heavy_count_][light_count_]};
  }

 private:
  const int kHeavyWeight = 100;
  const int kLightWeight = 50;
  const int64_t kModulo = 1000000007;
  int heavy_count_;
  int light_count_;
  int boat_capacity_;

  bool SolutionExists() {
    int max_weight = (heavy_count_ ? kHeavyWeight : kLightWeight);
    if (max_weight > boat_capacity_) {
      return false;
    }
    if (heavy_count_ + light_count_ >= 2){
      int min_weight = (light_count_ ? kLightWeight : kHeavyWeight);
      int next_min_weight = (light_count_ > 1 ? kLightWeight : kHeavyWeight);
      if (min_weight + next_min_weight > boat_capacity_) {
        return false;
      }
    }
    return true;
  }

  std::vector<std::vector<int64_t>> CalculateBinomials() {
    int limit = std::max(heavy_count_, light_count_);
    std::vector<std::vector<int64_t>> binomials(limit + 1);
    for(int i = 0; i <= limit; i++) {
      binomials[i].resize(i + 1);
      binomials[i][0] = binomials[i][i] = 1;
      for(int j = 1; j < i; j++){
        binomials[i][j] = (binomials[i - 1][j - 1] + binomials[i - 1][j]) % kModulo;
      }
    }
    return binomials;
  }
};

// To execute C++, please define "int main()"
int main() {
  BoatProblemSolver solver;
  solver.ReadData();
  std::pair<int, int64_t> boat_problem_solution = solver.SolveBoatProblem();
  std::cout << boat_problem_solution.first << std::endl;
  std::cout << boat_problem_solution.second << std::endl;
  return 0;
}


/*
Test #1:
1 50
50
Answer:
1
1

Test #2:
3 100
50 50 100
Answer:
5
2

Test #3:
2 50
50 50
Answer:
-1
0

*/