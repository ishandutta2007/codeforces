s = input()
m = int(input())
n = len(s)
s = s + s
assert(len(s) == 2 * n)
pot = []
pot.append(1)
for i in range(1, 212345):
	pot.append((pot[i - 1] * 10) % m)
cur = 0
mn = 1000000000
for i in range(0, 2 * n - 1):
	cur = (cur * 10 + ord(s[i]) - ord('0')) % m
	if i >= n:
		cur = (cur - (pot[n] * (ord(s[i - n]) - ord('0'))) % m + m) % m
	if i >= n - 1 and s[i - (n - 1)] != '0':
		mn = min(mn, cur)
print(mn)