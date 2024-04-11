points = []
for _ in range(3):
    a,b = map(int, input().split())
    points.append((a,b))
points.sort()

lines = []
def addLines(a, b):
    if a[0] == b[0]:
        lines.append((a[0], a[1], b[0], b[1]))
    else:
        lines.append((a[0], a[1], b[0], a[1]))
        lines.append((b[0], a[1], b[0], b[1]))
addLines(points[0], points[1])

yMin = min([elem[1] for elem in lines] + [elem[3] for elem in lines])
yMax = max([elem[1] for elem in lines] + [elem[3] for elem in lines])
if yMin <= points[2][1] <= yMax:
    assert points[2][0] != points[1][0]
    # reuse vertical line from before
    lines.append((points[1][0], points[2][1], points[2][0], points[2][1]))
else:
    closestPoint = points[1]
    def update(x,y):
        global closestPoint
        dist1 = abs(closestPoint[0] - points[2][0]) + abs(closestPoint[1] - points[2][1])
        dist2 = abs(x - points[2][0]) + abs(y - points[2][1])
        if dist2 < dist1:
            closestPoint = (x,y)
    for a,b,c,d in lines:
        update(a,b)
        update(c,d)
    addLines(closestPoint, points[2])
print(len(lines))
for elem in lines:
    print(" ".join(list(map(str, elem))))