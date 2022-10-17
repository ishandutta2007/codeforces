n = input()
s = ''
for i in range(n):
	if i > 0:
		s += 'that '
	if i % 2 == 0:
		s += 'I hate '
	else:
		s += 'I love '
s += 'it'
print s