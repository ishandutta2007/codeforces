const
  base=1000000007;

var
  cr,ct,res,i,j,k,c:longint;
  sn:ansistring;
  n:longint;
  f:array[0..15,0..2,0..15]of longint;
  a,u:array[0..15]of longint;
  
  procedure rec(t,x:longint);
    var
      i:longint;
      
    begin
      if (t<=0)then exit;
      if (x=8)then begin
        cr:=1;
        for i:=1 to 7 do begin
          ct:=u[a[i]];
          for j:=1 to i-1 do
            if (a[i]=a[j])then dec(Ct);
          if (ct<=0)then exit;
          cr:=int64(cr)*ct mod base;
        end;
        res:=(res+cr)mod base;
        exit;
      end;
      for i:=0 to 9 do begin
        a[x]:=i;
        rec(t-i,x+1);
      end;
    end;

begin
  read(n);
  str(n,sn);
  fillchar(f,sizeof(F),$0);
  f[1][0][0]:=1;
  for i:=1 to length(sn)do 
    for j:=0 to 1 do 
      for k:=0 to i do 
        if (f[i][j][k]<>0)then begin
          if (j=0)then begin
            for c:=0 to ord(sn[i])-48 do 
              inc(f[i+1][ord(c<ord(sn[i])-48)][k+ord((c=4)or(c=7))],f[i][j][k]);
          end else begin
            for c:=0 to 9 do 
              inc(f[i+1][1][k+ord((c=4)or(c=7))],f[i][j][k]);          
          end;
        end;
  for i:=0 to 9 do u[i]:=f[length(sn)+1][0][i]+f[length(sn)+1][1][i]-ord(i=0);
  res:=0;
  for i:=0 to 9 do begin
    a[1]:=i;
    rec(i,2);
  end;
  writeln(res);
end.