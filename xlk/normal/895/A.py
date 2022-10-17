n = input()
a = map(int, raw_input().split())
print min(abs(360-2*sum(a[j:i]))for i in range(n+1)for j in range(i))