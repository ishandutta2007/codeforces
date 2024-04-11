n = int(input())
sa, sb, sc = 0, 0, 0
for i in range(n):
    a, b, c = map(int, input().split())
    sa, sb, sc = sa+a, sb+b, sc+c
if((sa,sb,sc)==(0,0,0)):
    print('YES')
else:
    print('NO')