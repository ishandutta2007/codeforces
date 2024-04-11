[H, n] = [int(x) for x in input().split()]
d = [int(x) for x in input().split()]

H_old = H
mH = H

for i in range(n):
  H += d[i]
  mH = min(mH, H)
  if H <= 0:
    print(i+1)
    break;
else:
  if H_old <= H:
    print(-1)
  else:
    df = H_old - H
    mD = H_old - mH
    rnds = (mH+df-1) // df
    H = H_old - rnds * df
    for i in range(n):
      H += d[i]
      if H <= 0:
        print(rnds*n + i+1)
        break;