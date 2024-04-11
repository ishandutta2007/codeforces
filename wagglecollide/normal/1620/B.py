t = int(input())
for i in range(t):
    w, h = map(int, input().split())
    x1 = list(map(int, input().split()))[1:]
    x2 = list(map(int, input().split()))[1:]
    y1 = list(map(int, input().split()))[1:]
    y2 = list(map(int, input().split()))[1:]
    x1.sort()
    x2.sort()
    y1.sort()
    y2.sort()
    print(max(x1[-1] * h - x1[0] * h, x2[-1] * h - x2[0] * h, y1[-1] * w - y1[0] * w, y2[-1] * w - y2[0] * w))