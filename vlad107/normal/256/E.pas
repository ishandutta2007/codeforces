{$r-,q-,s-,i-,o+}
const
  base=777777777;

var
  y,x,res,n,tt,i,j,li,ri:longint;
  can:array[0..5,0..5]of longint;
  f:array[0..1000500,1..3,1..3]of longint;
  rev:array[0..1000500]of longint;
  
  procedure upd(x:longint);
    var
      ct,li,ri,m1,m2:longint;
      
    begin
      for li:=1 to 3 do 
        for ri:=1 to 3 do begin
          f[x][li][ri]:=0;
          for m1:=1 to 3 do 
            for m2:=1 to 3 do 
              if (can[m1][m2]=1)then begin
                ct:=f[x+x][li][m1];
                ct:=int64(ct)*f[x+x+1][m2][ri] mod base;
                inc(f[x][li][ri],ct);
                if (f[x][li][ri]>=base)then dec(f[x][li][ri],base);
              end;    
        end;
    end;
  
  procedure build(x,l,r:longint);
    begin
      if (l<r)then begin
        build(x+x,l,(l+r)shr 1);
        build(x+x+1,(l+r)shr 1+1,r);
        upd(x);
      end else begin
        rev[l]:=x;
        for i:=1 to 3 do 
          for j:=1 to 3 do 
            if (i=j)then f[x][i][j]:=1 else f[x][i][j]:=0;
      end;
    end;

begin
  //assign(input,'1.in');reset(input);
  //assign(output,'1.out');rewrite(output);
  read(n,tt);
  for i:=1 to 3 do for j:=1 to 3 do read(can[i][j]);
  build(1,1,n);
  while (tt>0)do begin
    dec(tt);
    read(x,y);
    x:=rev[x];
    for i:=1 to 3 do for j:=1 to 3 do f[x][i][j]:=0;
    for i:=1 to 3 do 
      if (y=0)or(i=y)then f[x][i][i]:=1;
    while (x>1)do begin
      x:=x shr 1;
      upd(x);
    end;
    res:=0;
    for li:=1 to 3 do 
      for ri:=1 to 3 do begin
        inc(res,f[1][li][ri]);
        if (res>=base)then dec(res,base);
      end;
    writeln(res);
  end;
end.