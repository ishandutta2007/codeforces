t = int(input())
def gan(s):
	if s == 'M':
		return 0
	if s[-1] == 'S':
		return -len(s)
	return len(s)
for tt in range(t):
	a, b = input().split()
	a = gan(a)
	b = gan(b)
	if a == b:
		print('=')
	elif a < b:
		print('<')
	else:
		print('>')