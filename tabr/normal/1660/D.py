tt = int(input())
for _ in range(tt):
    n = int(input())
    a = list(map(int, input().split()))
    beg = 0
    anssgn = 1
    anslog2 = 0
    ansbeg = n
    ansend = 0
    while beg < n:
        if a[beg] == 0:
            if anssgn == -1:
                anssgn = 0
                anslog2 = 0
                ansbeg = beg
                ansend = n - beg - 1
            beg += 1
            continue
        end = beg
        while end < n and a[end] != 0:
            end += 1
        sgn = 1
        log2 = 0
        for i in range(beg, end):
            if a[i] < 0:
                sgn *= -1
            if abs(a[i]) == 2:
                log2 += 1
            if sgn * (log2 + 1) > anssgn * (anslog2 + 1):
                anssgn = sgn
                anslog2 = log2
                ansbeg = beg
                ansend = n - 1 - i
        sgn = 1
        log2 = 0
        for i in reversed(range(beg, end)):
            if a[i] < 0:
                sgn *= -1
            if abs(a[i]) == 2:
                log2 += 1
            if sgn * (log2 + 1) > anssgn * (anslog2 + 1):
                anssgn = sgn
                anslog2 = log2
                ansbeg = i
                ansend = n - end
        beg = end
    print(ansbeg, ansend)