t = int(input())
for i in range(t):
    s = input()
    n = len(s)
    count_e = s.count('E')
    count_n = s.count('N')
    if count_e == 0 or count_n == 0:
        print('YES')
        continue
    if n == 2 or count_n == 1:
        print('NO')
        continue
    if count_e == 1 and count_n == 2:
        s += s[0]
        for j in range(n):
            if s[j] == 'E' and s[j + 1] == 'E':
                print('NO')
                break
        else:
            print('YES')
        continue
    print('YES')