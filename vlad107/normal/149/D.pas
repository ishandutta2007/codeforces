{$r-,q-,s-,i-,o+}
const
  base=1000000007;

var
  s:ansistring;
  f:array[0..777,0..777,0..3,0..3]of longint;
  pair,st:array[0..500500]of longint;
  i,kst:longint;

  procedure calc(l,r,x,y:longint);
    var
      cx,cy,cr1,cr2,res:longint;

    begin
      if (l>r)then begin
        f[l][r][x][y]:=1;
        exit;
      end;
      if (f[l][r][x][y]<>-1)then exit;
      f[l][r][x][y]:=0;
      for cx:=0 to 2 do
        for cy:=0 to 2 do begin
          if (cx=0)and(cy=0)then continue;
          if (cx<>0)and(cy<>0)then continue;
          if (cx=x)and(cx<>0)then continue;
          if (cy=y)and(cy<>0)and(pair[l]=r)then continue;
          calc(l+1,pair[l]-1,cx,cy);
          cr1:=f[l+1][pair[l]-1][cx][cy];
          calc(pair[l]+1,r,cy,y);
          cr2:=f[pair[l]+1][r][cy][y];
          res:=int64(cr1)*cr2 mod base;
          f[l][r][x][y]:=(f[l][r][x][y]+res)mod base;
        end;
    end;

begin
  readln(s);
  kst:=0;
  for i:=1 to length(s)do
    if (s[i]='(')then begin
      inc(kst);st[kst]:=i;
    end else begin
      pair[st[kst]]:=i;
      dec(kst);
    end;
  fillchar(f,sizeof(f),$FF);
  calc(1,length(s),3,3);
  writeln(f[1][length(s)][3][3]);
end.