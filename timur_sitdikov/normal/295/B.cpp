#include <iostream>
#include <vector>

class Graph {
 public:
  void ReadGraph() {
    int n;
    std::cin >> n;
    adjacency_matrix_.resize(n);
    for(int i = 0; i < n; i++){
      adjacency_matrix_[i].resize(n);
      for(int j = 0; j < n; j++) {
        std::cin >> adjacency_matrix_[i][j];
      }
    }
    deleted_vertices_.resize(n);
    for(int i = 0; i < n; i++) {
      std::cin >> deleted_vertices_[i];
      deleted_vertices_[i]--;
    }
  }

  std::vector<int64_t> GetSumOfMinimalDistances() {
    int n = adjacency_matrix_.size();
    std::vector<std::vector<int>> minimal_distances(n);
    for(int i = 0; i < n; i++) {
      minimal_distances[i].resize(n);
      for(int j = 0; j < n; j++) {
        minimal_distances[i][j] = (i == j ? 0 : adjacency_matrix_[i][j]);
      }
    }
    std::vector<int64_t> sum_of_minimal_distances(n);
    for(int i = n - 1; i >= 0; i--){
      int vertex = deleted_vertices_[i];
      for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
          minimal_distances[j][k] = std::min(
            minimal_distances[j][k],
            minimal_distances[j][vertex] + minimal_distances[vertex][k]);
        }
      }
      for(int j = i; j < n; j++) {
        for(int k = i; k < n; k++) {
          sum_of_minimal_distances[i] += (
            minimal_distances[deleted_vertices_[j]][deleted_vertices_[k]]);
        }
      }
    }
    return sum_of_minimal_distances;
  }

 private:
  std::vector<std::vector<int>> adjacency_matrix_;
  std::vector<int> deleted_vertices_;
};

// To execute C++, please define "int main()"
int main() {
  Graph graph;
  graph.ReadGraph();
  std::vector<int64_t> sum_of_minimal_distances = graph.GetSumOfMinimalDistances();
  for(size_t i = 0; i < sum_of_minimal_distances.size(); i++){
    std::cout << sum_of_minimal_distances[i] << " ";
  }
  return 0;
}