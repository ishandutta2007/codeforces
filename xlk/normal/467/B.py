n, m, k = map(int, raw_input().split())
a = [input() for i in range(m)]
b = input()
print sum(bin(i ^ b).count('1') <= k for i in a)