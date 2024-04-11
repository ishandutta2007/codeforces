
n=int(raw_input())

s=[k for k in raw_input().split(" ")]

def root(w):
	return "".join(sorted(list(set(w))))
	
ss=set()
for k in s:
	ss.add(root(k))
	
print len(ss)