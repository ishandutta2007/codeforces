{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 100000000}
const dx: array [1..4] of longint = (0,1,0,-1);
      dy: array [1..4] of longint = (1,0,-1,0);
var
  ans,px,py,c: array [0..1010,0..1010] of longint;
  q,xk,yk,it,n,m,i,j,e,ii,jj: longint;
  ws: array [0..1010] of longint;
  gx,gy: array [0..1010,0..1010,0..5] of longint;
  kw,x,y: array [0..1000010] of longint;
  wx,wy: array [0..1000010,0..5] of longint;
  kg: array [0..1010,0..1010] of longint;
  a: array [0..1010,0..1010] of char;
  was: array [0..1010,0..1010] of boolean;

procedure rec(i,j:longint);
var
  q,ii,jj: longint;
  leavy: boolean;
begin
  inc(it);
  kw[it]:=1;
  wx[it,1]:=i;
  wy[it,1]:=j;
  c[i,j]:=it;
  leavy:=False;
  for q:=1 to kg[i,j] do
    if kg[gx[i,j,q],gy[i,j,q]] = 0 then
    begin
      inc(kw[it]);
      wx[it,kw[it]]:=gx[i,j,q];
      wy[it,kw[it]]:=gy[i,j,q];
      c[gx[i,j,q],gy[i,j,q]]:=it;
      leavy:=True;
    end;
  if not leavy then
  begin
    ii:=gx[i,j,1];
    jj:=gy[i,j,1];
    inc(kw[it]);
    wx[it,kw[it]]:=ii;
    wy[it,kw[it]]:=jj;
    c[ii,jj]:=it;
    for q:=1 to kg[ii,jj] do
      if kg[gx[ii,jj,q],gy[ii,jj,q]] = 0 then
      begin
        inc(kw[it]);
        wx[it,kw[it]]:=gx[ii,jj,q];
        wy[it,kw[it]]:=gy[ii,jj,q];
        c[gx[ii,jj,q],gy[ii,jj,q]]:=it;
      end;
    for q:=1 to kg[ii,jj] do
      if kg[gx[ii,jj,q],gy[ii,jj,q]] > 0 then
        rec(gx[ii,jj,q],gy[ii,jj,q]);
    for q:=2 to kg[i,j] do
      rec(gx[i,j,q],gy[i,j,q]);
  end else
    for q:=1 to kg[i,j] do
      if kg[gx[i,j,q],gy[i,j,q]] > 0 then
        rec(gx[i,j,q],gy[i,j,q]);
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(n,m);
  fillchar(a,sizeof(a),'#');
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  for ii:=0 to n+1 do
    for jj:=0 to m+1 do
      if a[ii,jj] = '#' then was[ii,jj]:=True
      else was[ii,jj]:=False;
  fillchar(c,sizeof(c),0);
  fillchar(kg,sizeof(kg),0);
  for ii:=1 to n do
    for jj:=1 to m do
      if not was[ii,jj] then
      begin
        i:=1; e:=1;
        x[1]:=ii;
        y[1]:=jj;
        was[ii,jj]:=True;
        while i <= e do
        begin
          for j:=1 to 4 do
          begin
            xk:=x[i]+dx[j];
            yk:=y[i]+dy[j];
            if (xk > 0) and (yk > 0) and (xk <= n) and (yk <= m) then
              if not was[xk,yk] then
              begin
                inc(e);
                x[e]:=xk;
                y[e]:=yk;
                px[xk,yk]:=x[i];
                py[xk,yk]:=y[i];
                inc(kg[x[i],y[i]]);
                gx[x[i],y[i],kg[x[i],y[i]]]:=xk;
                gy[x[i],y[i],kg[x[i],y[i]]]:=yk;
                was[xk,yk]:=True;
              end;
          end;
          inc(i);
        end;
        if e = 1 then
        begin
          writeln(-1);
          halt;
        end;
        it:=0;
        rec(ii,jj);
        for q:=0 to 9 do ws[q]:=0;
        for i:=1 to it do
        begin
          for q:=1 to kw[i] do
            for j:=1 to 4 do
            begin
              xk:=wx[i,q]+dx[j];
              yk:=wy[i,q]+dy[j];
              if (c[xk,yk] > 0) and (c[xk,yk] < i) then
                ws[ans[xk,yk]]:=i;
            end;
          j:=0;
          while ws[j] = i do inc(j);
          for q:=1 to kw[i] do
            ans[wx[i,q],wy[i,q]]:=j;
        end;
      end;
  for i:=1 to n do
  begin
    for j:=1 to m do
      if a[i,j] = '#' then write(a[i,j])
      else write(Chr(48+ans[i,j]));
    writeln;
  end;
  close(input);
  close(output);
end.