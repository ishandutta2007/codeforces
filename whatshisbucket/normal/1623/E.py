import sys
I=lambda:[*map(int, sys.stdin.readline().split())]

left = []
right = []
n, k = I()
parents = [-1] * n
s = input()
for i in range(n):
	l, r = I()
	l -= 1
	r -= 1
	left.append(l)
	right.append(r)
	if l >= 0:
		parents[l] = i
	if r >= 0:
		parents[r] = i

covered = [0] * n
covered.append(1)
order = []
curr = 0
while len(order) < n:
	if covered[left[curr]]:
		if covered[curr]:
			if covered[right[curr]]:
				curr = parents[curr]
			else:
				curr = right[curr]
		else:
			covered[curr] = 1
			order.append(curr)
	else:
		curr = left[curr]

after = 'a'
want = [0] * n
curr = s[order[-1]]
for i in range(n - 2, -1, -1):
	new = s[order[i]]
	if new != curr:
		after = curr
		curr = new
	if curr < after:
		want[order[i]] = 1

dist = [float('inf')] * n
for v in order:
	if want[v]:
		dist[v] = 0
	elif left[v] >= 0:
		dist[v] = dist[left[v]] + 1

dupe = [0] * n
checked = [0] * n
curr = 0
lef = k
while lef > 0 and curr != -1:
	if dupe[curr]:
		if left[curr] >= 0 and dupe[left[curr]] == 0 and checked[left[curr]] == 0:
			curr = left[curr]
		elif right[curr] >= 0 and dupe[right[curr]] == 0 and checked[right[curr]] == 0:
			curr = right[curr]
		else:
			curr = parents[curr]
	else:
		if dist[curr] < lef:
			lef -= dist[curr] + 1
			dupe[curr] = 1
			for i in range(dist[curr]):
				curr = left[curr]
				dupe[curr] = 1
		else:
			checked[curr] = 1
			curr = parents[curr]

out = []
for guy in order:
	if dupe[guy]:
		out.append(2 * s[guy])
	else:
		out.append(s[guy])
print(''.join(out))