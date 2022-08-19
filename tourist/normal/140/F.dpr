{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const two: int64 = 2;
      inf = round(2.1e9);
var
  cnt,tmp,xm,ym,ans,n,k,ii,jj,i,j: longint;
  q: int64;
  xt,yt,ax,ay,x,y: array [0..200010] of longint;

procedure Sort(l,r:longint);
var
  i,j,pp,xx,yy,tmp: longint;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  xx:=x[pp]; yy:=y[pp];
  repeat
    while (x[i] < xx) or (x[i] = xx) and (y[i] < yy) do inc(i);
    while (xx < x[j]) or (xx = x[j]) and (yy < y[j]) do dec(j);
    if i <= j then
    begin
      tmp:=x[i]; x[i]:=x[j]; x[j]:=tmp;
      tmp:=y[i]; y[i]:=y[j]; y[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure SortT(l,r:longint);
var
  i,j,pp,xx,yy,tmp: longint;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  xx:=xt[pp]; yy:=yt[pp];
  repeat
    while (xt[i] < xx) or (xt[i] = xx) and (yt[i] < yy) do inc(i);
    while (xx < xt[j]) or (xx = xt[j]) and (yy < yt[j]) do dec(j);
    if i <= j then
    begin
      tmp:=xt[i]; xt[i]:=xt[j]; xt[j]:=tmp;
      tmp:=yt[i]; yt[i]:=yt[j]; yt[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortT(l,j);
  if i < r then SortT(i,r);
end;

procedure print(x:longint);
begin
  if x < 0 then
  begin
    write('-');
    x:=-x;
  end;
  write(x shr 1,'.',x and 1*5);
end;

begin
  randomize;
{  assign(input,'in'); reset(input);
  assign(output,'out'); rewrite(output);}
  read(n,k);
  if n <= k then
  begin
    writeln(-1);
    halt;
  end;
  for i:=1 to n do
  begin
    read(x[i],y[i]);
    x[i]:=x[i]*2;
    y[i]:=y[i]*2;
  end;
  Sort(1,n);
  ans:=0;
  for ii:=1 to k+1 do
    for jj:=n-k to n do
      if (ii-1)+(n-jj) <= k then
      begin
        xm:=(x[ii]+x[jj]) div 2;
        ym:=(y[ii]+y[jj]) div 2;
        for i:=1 to n do
        begin
          q:=two*xm-x[i];
          if q > inf then q:=inf;
          if q < -inf then q:=-inf;
          xt[i]:=q;
          q:=two*ym-y[i];
          if q > inf then q:=inf;
          if q < -inf then q:=-inf;
          yt[i]:=q;
        end;
        SortT(1,n);
        i:=1; j:=1;
        cnt:=0;
        while (i <= n) and (j <= n) do
          if (x[i] < xt[j]) or (x[i] = xt[j]) and (y[i] < yt[j]) then inc(i) else
          if (x[i] > xt[j]) or (x[i] = xt[j]) and (y[i] > yt[j]) then inc(j) else
          begin
            inc(i); inc(j);
            inc(cnt);
          end;
        if n-cnt <= k then
        begin
          inc(ans);
          ax[ans]:=xm;
          ay[ans]:=ym;
        end;
      end;
  for i:=1 to ans-1 do
    for j:=i+1 to ans do
      if (ax[i] > ax[j]) or (ax[i] = ax[j]) and (ay[i] > ay[j]) then
      begin
        tmp:=ax[i]; ax[i]:=ax[j]; ax[j]:=tmp;
        tmp:=ay[i]; ay[i]:=ay[j]; ay[j]:=tmp;
      end;
  j:=0;
  for i:=1 to ans do
    if (i = 1) or (ax[i] <> ax[i-1]) or (ay[i] <> ay[i-1]) then
    begin
      inc(j);
      ax[j]:=ax[i];
      ay[j]:=ay[i];
    end;
  writeln(j);
  for i:=1 to j do
  begin
    print(ax[i]);
    write(' ');
    print(ay[i]);
    writeln;
  end;
{  close(input);
  close(output);}
end.