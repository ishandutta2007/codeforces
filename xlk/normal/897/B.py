n, p = map(int, raw_input().split())
print sum(int(str(i) + str(i)[::-1])for i in range(n+1))%p