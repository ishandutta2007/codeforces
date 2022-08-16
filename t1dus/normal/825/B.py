from copy import deepcopy
a = []
for _ in range(10):
    a.append(list(input()))
ans = False   
for i in range(10):
    for j in range(10):
        if a[i][j] != '.': continue
        b = deepcopy(a)
        b[i][j] = 'X'
        for k in range(10):
            for l in range(6):
                if b[k][l] == b[k][l+1] == b[k][l+2] == b[k][l+3] == b[k][l+4] == 'X':
                    ans = True
                if b[l][k] == b[l+1][k] == b[l+2][k] == b[l+3][k] == b[l+4][k] == 'X':
                    ans = True    
        for k in range(2,8):
            for l in range(2,8):
                if b[k-2][l-2] == b[k-1][l-1] == b[k][l] == b[k+1][l+1] == b[k+2][l+2] == 'X':
                    ans = True
                if b[k-2][l+2] == b[k-1][l+1] == b[k][l] == b[k+1][l-1] == b[k+2][l-2] == 'X':
                    ans = True    
                    
if ans:
    print("YES")
else:
    print("NO")