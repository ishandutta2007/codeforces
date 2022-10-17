n = input()
a = input()
b = input()
for i in range(min(a, b, n / max(a, b) + 1)):
	if (n - i * a) % b == 0:
		print 'YES\n', i, (n - i * a) / b
		break
	if (n - i * b) % a == 0:
		print 'YES\n', (n - i * b) / a, i
		break
else:
	print 'NO'