import sys

n=int(sys.stdin.readline())
vals=[int(x) for x in sys.stdin.readline().split()]

import operator
diffs=list(set(
	r for x,y in zip(vals[1:],vals) for r in (abs(x-y),) if r!=1
))

if len(diffs)>1 or 0 in diffs:
	print("NO")
	sys.exit()

if not diffs:
	# all of them are 1-change
	print("YES")
	print(f"{10**9} {10**9}")
	sys.exit()

j=diffs[0]
for i in range(1,n):
	if abs(vals[i-1]-vals[i])!=1:continue
	if (vals[i-1]-1)//j != (vals[i]-1)//j:
		print("NO")
		sys.exit()


print("YES")
print(f"{10**9} {j}")