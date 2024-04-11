#include <iostream>
#include <cmath>
using namespace std;

int xor_result(int *arr, int n);
long long arr_sum(int *arr, int amount);

long long first_add(int *arr, int amount);
long long second_third_add(int *arr, int amount, long long added);

int main() 
{
	int t, amount, arr[100003], result;
	cin >> t;
	while (t--) {
		cin >> amount;
		for (int i = 0; i < amount; ++i) cin >> arr[i];
		
		long long added = first_add(arr, amount), added2 = second_third_add(arr, amount, added);
		cout << "3\n";
		cout << added << ' ' << added2 << ' ' << added2 << '\n';
	}
	return 0;
}

int xor_result(int *arr, int n) 
{
	int result = 0;
	while (n--) result ^= *(arr + n);
	return result;
}
long long arr_sum(int *arr, int amount) 
{
	long long sum = 0;
	for (int i = 0; i < amount; ++i) sum += arr[i];
	return sum;
}

long long first_add(int *arr, int amount) 
{
	int exp_2 = 0;
	long long sum = arr_sum(arr, amount);
	while (pow(2, exp_2) <= sum) ++exp_2;
	if (!exp_2) return 0;
	if (xor_result(arr, amount) % 2) return pow(2, exp_2) + 1;
	else return pow(2, exp_2);
}
long long second_third_add(int *arr, int amount, long long added) 
{
	return (xor_result(arr, amount) + (added - added % 2) - added % 2) - (arr_sum(arr, amount) + added) / 2;
}