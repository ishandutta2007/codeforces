x1,y1,x2,y2,x3,y3=gets(p).split.map &:to_i
puts ["TOWARDS","RIGHT","LEFT"][(x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)<=>0]