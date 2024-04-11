{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
{$M 50000000}
var
  cnt,iii,beg,fin,kc,mm,n,m,i,ii,e,j,ans: longint;
  f,g,deg,ver,pv,c,de,md,ss,ff,pr,pz,ls,x,sss,fff,pred,last: array [0..200010] of longint;
  good,ws,was: array [0..200010] of boolean;

procedure rec(v,depth:longint);
var
  j: longint;
begin
  ws[v]:=True;
  de[v]:=depth;
  md[v]:=depth;
  j:=ls[v];
  while j > 0 do
  begin
    if not ws[ff[j]] then
    begin
      pv[ff[j]]:=j;
      rec(ff[j],depth+1);
      if md[ff[j]] < md[v] then md[v]:=md[ff[j]];
    end else
    if ff[j] <> ss[pv[v]] then
      if de[ff[j]] < md[v] then md[v]:=de[ff[j]];
    j:=pr[j];
  end;
end;

procedure solve(v:longint);
var
  j,q,max1,max2: longint;
begin
  ws[v]:=True;
  f[v]:=0;
  max1:=0; max2:=0;
  j:=ls[v];
  while j > 0 do
  begin
    q:=ff[j];
    if not ws[q] then
    begin
      solve(q);
      if f[q] > f[v] then f[v]:=f[q];
      if g[q]+1 > max1 then
      begin
        max2:=max1;
        max1:=g[q]+1;
      end else
      if g[q]+1 > max2 then max2:=g[q]+1;
    end;
    j:=pr[j];
  end;
  g[v]:=max1;
  if max1+max2 > f[v] then f[v]:=max1+max2;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  for i:=1 to m do
  begin
    read(sss[i],fff[i]);
    sss[i+m]:=fff[i];
    fff[i+m]:=sss[i];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[sss[i]];
    last[sss[i]]:=i;
  end;
  fillchar(was,sizeof(was),False);
  fillchar(pz,sizeof(pz),0);
  ans:=-1;
  for ii:=1 to n do
    if not was[ii] then
    begin
      inc(ans);
      i:=1; e:=1;
      x[1]:=ii;
      pz[ii]:=1;
      was[ii]:=True;
      while i <= e do
      begin
        j:=last[x[i]];
        while j > 0 do
        begin
          if not was[fff[j]] then
          begin
            inc(e);
            x[e]:=fff[j];
            pz[x[e]]:=e;
            was[x[e]]:=True;
          end;
          j:=pred[j];
        end;
        inc(i);
      end;
      for i:=1 to e do ls[i]:=0;
      mm:=0;
      for i:=1 to e do
      begin
        j:=last[x[i]];
        while j > 0 do
        begin
          if sss[j] < fff[j] then
          begin
            inc(mm);
            ss[mm]:=pz[sss[j]];
            ff[mm]:=pz[fff[j]];
          end;
          j:=pred[j];
        end;
      end;
      for i:=1 to mm do
      begin
        ss[i+mm]:=ff[i];
        ff[i+mm]:=ss[i];
      end;
      for i:=1 to mm+mm do
      begin
        pr[i]:=ls[ss[i]];
        ls[ss[i]]:=i;
      end;
      for i:=1 to e do ws[i]:=False;
      pv[1]:=0;
      rec(1,1);
      for i:=1 to mm+mm do good[i]:=True;
      for i:=2 to e do
        if de[i] = md[i] then
        begin
          good[pv[i]]:=False;
          if pv[i] <= mm then good[pv[i]+mm]:=False
          else good[pv[i]-mm]:=False;
        end;
      for i:=1 to e do c[i]:=0;
      kc:=0;
      for iii:=1 to e do
        if c[iii] = 0 then
        begin
          beg:=1; fin:=1;
          ver[beg]:=iii;
          inc(kc);
          c[iii]:=kc;
          while beg <= fin do
          begin
            j:=ls[ver[beg]];
            while j > 0 do
            begin
              if good[j] and (c[ff[j]] = 0) then
              begin
                inc(fin);
                ver[fin]:=ff[j];
                c[ff[j]]:=kc;
              end;
              j:=pr[j];
            end;
            inc(beg);
          end;
          inc(ans,fin-1);
        end;
      for i:=1 to kc do ls[i]:=0;
      for i:=1 to mm+mm do
      begin
        ss[i]:=c[ss[i]];
        ff[i]:=c[ff[i]];
        if ss[i] <> ff[i] then
        begin
          pr[i]:=ls[ss[i]];
          ls[ss[i]]:=i;
        end else
        begin
          ss[i]:=0;
          ff[i]:=0;
        end;
      end;
      if kc = 1 then continue;
      for i:=1 to kc do deg[i]:=0;
      for i:=1 to mm+mm do
        if ss[i] <> 0 then inc(deg[ss[i]]);
      cnt:=0;
      for i:=1 to kc do
        if deg[i] < 2 then inc(cnt);
      for i:=1 to kc do ws[i]:=False;
      solve(1);
      ans:=ans+kc-f[1]-cnt+1;
    end;
  writeln(ans);
  close(input);
  close(output);
end.