N, K = [int(x) for x in raw_input().split(' ')]
T = raw_input().split(' ')

C = int(T[0])
S = [int(x) for x in T[1:]]

s, t = 0, 0
for d in S:
    while t+K<d:
        t += K
        s += 1
    t = d
    s += 1
while t+K<N+1:
    t += K
    s += 1

print(s)