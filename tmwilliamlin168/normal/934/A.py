n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
print(min(max(a[j]*k for k in b for j in range(n) if j!=i) for i in range(n)))