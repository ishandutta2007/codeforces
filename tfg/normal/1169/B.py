n, m =  map(int, raw_input().split())

ar = []
dici = {}

for k in xrange(m):
	
	inputt = sorted(map(int, raw_input().split()))
	inputt = (inputt[0], inputt[1])
	if inputt not in dici:
		dici[inputt] = 0
		ar.append(inputt)
	
def solve(a, fixed):
	for pair in a:
		good = False
		for val in fixed:
			if val == pair[0] or val == pair[1]:
				good = True
		if not good:
			if len(fixed) == 2:
				return False
			for val in pair:
				fixed.append(val)
				if solve(a, fixed):
					return True
				fixed.pop()
			return False
	return True

fixed = []
if solve(ar, fixed):
	print('YES')
else:
	print('NO')