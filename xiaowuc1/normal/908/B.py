def valid(g, dirs, moves):
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    currX = -1
    currY = -1
    for i in xrange(len(g)):
        for j in xrange(len(g[i])):
            if g[i][j] == 'S':
                currX = i
                currY = j
    for i in xrange(len(moves)):
        trueDir = ord(moves[i]) - ord('0')
        nx = currX + dx[dirs[trueDir]]
        ny = currY + dy[dirs[trueDir]]
        if nx < 0 or nx >= len(g) or ny < 0 or ny >= len(g[nx]):
            return False
        if g[nx][ny] == 'E':
            return True
        if g[nx][ny] == '#':
            return False
        currX = nx
        currY = ny
    return False
    
def dfs(g, l, moves):
    if len(l) == 4:
        return 1 if valid(g, l, moves) else 0
    ret = 0
    for x in xrange(0, 4):
        if x not in l:
            l.append(x)
            ret += dfs(g, l, moves)
            l.pop()
    return ret

r, c = (int(x) for x in raw_input().split())
g = []
for _ in xrange(r):
    g.append(raw_input())
moves = raw_input()
print dfs(g, [], moves)