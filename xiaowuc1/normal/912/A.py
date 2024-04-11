y, b = (int(x) for x in raw_input().split())
qq, ww, ee = (int(x) for x in raw_input().split())

truey = 2*qq + 1*ww
trueb = 1*ww + 3*ee
print max(0, truey-y) + max(0, trueb-b)