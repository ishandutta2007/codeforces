v = ['a', 'e', 'i', 'o', 'u', 'y']
input()
s = ''
for i in raw_input():
	if len(s) == 0:
		s += i
	elif s[-1] not in v or i not in v:
		s += i
print s