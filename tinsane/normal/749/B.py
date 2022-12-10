# 211693RAVMK

def f(p1, p2, p3):
    o = ((p2[0] + p3[0]) // 2, (p2[1] + p3[1]) // 2)
    dx = o[0] - p1[0]
    dy = o[1] - p1[1]
    res = (p1[0] // 2 + dx, p1[1] // 2 + dy)
    return res


def main():
     p1 = tuple(map(lambda x: int(x)*2, input().split()))
     p2 = tuple(map(lambda x: int(x)*2, input().split()))
     p3 = tuple(map(lambda x: int(x)*2, input().split()))
     d2 = (p2[0] - p1[0], p2[1] - p1[1])
     d3 = (p3[0] - p1[0], p3[1] - p1[1])
     if d2[0] * d3[1] - d2[1] * d3[0] == 0:
         print(0)
         return
     res = set()
     res.add(f(p1, p2, p3))
     res.add(f(p2, p1, p3))
     res.add(f(p3, p2, p1))
     print(len(res))
     for p in res:
         print(' '.join(map(str, p)))

 
if __name__=='__main__':
    main()