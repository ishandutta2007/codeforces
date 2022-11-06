K=int(raw_input())
tc=[int(k) for k in raw_input().split(" ")]
mtc=max(tc)
if mtc<=25:
	print 0
else:
	print mtc-25