raw_input()
a = set(raw_input().split())
b = set(raw_input().split())
if a & b:
	print min(a & b)
else:
	print ''.join(sorted((min(a), min(b))))