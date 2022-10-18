d=set()
for s in [input() for i in range(int(input()))]:
    print('YES' if s in d else 'NO')
    d|={s}