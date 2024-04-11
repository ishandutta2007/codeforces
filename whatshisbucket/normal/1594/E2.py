k = int(input())
n = int(input())
l = [1]
m = 10**9+7
for i in range(k-1):
	l.append((16*l[-1]**2)%m)

counts = {}
ind = {'white':0,'green':1,'red':2,'yellow':3,'blue':4,'orange':5}
given = {}
for i in range(n):
	v, c = input().split()
	v = int(v)
	c = ind[c]
	given[v]=c

def count(k,i,counts,color=None):
	if i in counts:
		return None
	m=10**9+7
	if 2*i not in counts and 2*i+1 not in counts:
		layer = len(bin(i))-2
		if color is None:
			counts[i] = [l[k-layer]]*6
		else:
			counts[i] = [0]*6
			counts[i][color] = l[k-layer]
	elif 2*i in counts and 2*i+1 in counts:
		left = counts[2*i]
		right = counts[2*i+1]
		new = [0]*6
		for _ in range(6):
			totleft = sum(left)-left[_]-left[(_+3)%6]
			totright = sum(right)-right[_]-right[(_+3)%6]
			if color is None or _==color:
				new[_] = (totleft*totright)%m
		counts[i] = new
	else:
		layer = len(bin(i))-2
		if 2*i in counts:
			left = counts[2*i]
			right = [l[k-layer-1]]*6
		else:
			left = counts[2*i+1]
			right = [l[k-layer-1]]*6
		new = [0]*6
		for _ in range(6):
			totleft = sum(left)-left[_]-left[(_+3)%6]
			totright = sum(right)-right[_]-right[(_+3)%6]
			if color is None or _==color:
				new[_] = (totleft*totright)%m
		counts[i] = new

bits = k
while bits > 0:
	for guy in list(counts.keys()):
		if len(bin(guy)) == bits+3:
			if guy//2 in given:
				color = given[guy//2]
			else:
				color = None
			count(k, guy//2, counts, color)
	for guy in given:
		if len(bin(guy)) == bits+2:
			count(k,guy,counts,given[guy])
	bits -= 1
print(sum(counts[1])%m)