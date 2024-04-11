t = int(input())
for i in range(t):
    s = input()
    if s.rfind('po') == len(s)-2:
        print('FILIPINO')
    elif s.rfind('desu') == len(s)-4 or s.rfind('masu') == len(s)-4:
        print('JAPANESE')
    else:
        print('KOREAN')