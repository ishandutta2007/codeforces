input()
a = map(int, raw_input().split())
s = 0
for i in a:
	s += abs(i)
print s