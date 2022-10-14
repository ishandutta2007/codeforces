#include <bits/stdc++.h>

using namespace std;

int main() {
	int number_of_test_cases; cin >> number_of_test_cases;
	for (int test_case = 1; test_case <= number_of_test_cases; test_case++) {
		int number_of_nodes, number_of_edges, max_diameter;
		cin >> number_of_nodes >> number_of_edges >> max_diameter;
		long long max_edges = (long long) number_of_nodes * (number_of_nodes - 1) / 2;
		if (number_of_edges < number_of_nodes - 1 || max_edges < number_of_edges) {
			cout << "NO\n"; continue;
		}
		if (number_of_nodes == 1) {
			cout << (max_diameter >= 2 ? "YES\n" : "NO\n");
		} else if (max_edges == number_of_edges) {
			cout << (max_diameter >= 3 ? "YES\n" : "NO\n");
		} else {
			cout << (max_diameter >= 4 ? "YES\n" : "NO\n");
		}
	}
}