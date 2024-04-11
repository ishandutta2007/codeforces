d = raw_input()
key = 'qwertyuiopasdfghjkl;zxcvbnm,./'
if d == 'R':
	d = -1
else:
	d = +1

s = raw_input()
t = ''
for i in s:
	t += key[key.index(i) + d]
print t