t = int(input())
for _ in range(t):
    cnt = {'L': 0, 'R': 0, 'U': 0, 'D': 0}
    for c in input():
        cnt[c] += 1
    a, b = min(cnt['L'], cnt['R']), min(cnt['U'], cnt['D'])
    if b<1 and a>0:
        a=1
    if a<1 and b>0:
        b=1
    print(2*(a+b))
    print('L'*a+'U'*b+'R'*a+'D'*b)