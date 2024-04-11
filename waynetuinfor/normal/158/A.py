n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
print(sum([(a[i] >= a[k - 1] and a[i] > 0) for i in range(n)]))