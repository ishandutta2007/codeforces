#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 3e8 + 5;
const int D = 1000000;

int cnt[MAXN / D + 1];

void init() {
	cnt[0] = 39176;
	cnt[1] = 35241;
	cnt[2] = 33867;
	cnt[3] = 33219;
	cnt[4] = 32691;
	cnt[5] = 32139;
	cnt[6] = 31928;
	cnt[7] = 31499;
	cnt[8] = 31341;
	cnt[9] = 31080;
	cnt[10] = 30899;
	cnt[11] = 30913;
	cnt[12] = 30576;
	cnt[13] = 30405;
	cnt[14] = 30301;
	cnt[15] = 30139;
	cnt[16] = 30087;
	cnt[17] = 30002;
	cnt[18] = 29854;
	cnt[19] = 29814;
	cnt[20] = 29600;
	cnt[21] = 29719;
	cnt[22] = 29406;
	cnt[23] = 29422;
	cnt[24] = 29436;
	cnt[25] = 29274;
	cnt[26] = 29336;
	cnt[27] = 29150;
	cnt[28] = 29172;
	cnt[29] = 29094;
	cnt[30] = 29091;
	cnt[31] = 28875;
	cnt[32] = 28873;
	cnt[33] = 28902;
	cnt[34] = 28653;
	cnt[35] = 28729;
	cnt[36] = 28749;
	cnt[37] = 28687;
	cnt[38] = 28754;
	cnt[39] = 28595;
	cnt[40] = 28584;
	cnt[41] = 28417;
	cnt[42] = 28392;
	cnt[43] = 28489;
	cnt[44] = 28355;
	cnt[45] = 28315;
	cnt[46] = 28386;
	cnt[47] = 28313;
	cnt[48] = 28256;
	cnt[49] = 28258;
	cnt[50] = 28169;
	cnt[51] = 28080;
	cnt[52] = 28070;
	cnt[53] = 28052;
	cnt[54] = 28033;
	cnt[55] = 28035;
	cnt[56] = 27971;
	cnt[57] = 28017;
	cnt[58] = 27892;
	cnt[59] = 27899;
	cnt[60] = 27976;
	cnt[61] = 27713;
	cnt[62] = 27847;
	cnt[63] = 27868;
	cnt[64] = 27831;
	cnt[65] = 27821;
	cnt[66] = 27783;
	cnt[67] = 27794;
	cnt[68] = 27716;
	cnt[69] = 27699;
	cnt[70] = 27611;
	cnt[71] = 27660;
	cnt[72] = 27723;
	cnt[73] = 27534;
	cnt[74] = 27588;
	cnt[75] = 27680;
	cnt[76] = 27510;
	cnt[77] = 27458;
	cnt[78] = 27448;
	cnt[79] = 27443;
	cnt[80] = 27498;
	cnt[81] = 27578;
	cnt[82] = 27454;
	cnt[83] = 27448;
	cnt[84] = 27327;
	cnt[85] = 27347;
	cnt[86] = 27304;
	cnt[87] = 27472;
	cnt[88] = 27326;
	cnt[89] = 27266;
	cnt[90] = 27219;
	cnt[91] = 27227;
	cnt[92] = 27345;
	cnt[93] = 27189;
	cnt[94] = 27308;
	cnt[95] = 27228;
	cnt[96] = 27199;
	cnt[97] = 27167;
	cnt[98] = 27086;
	cnt[99] = 27143;
	cnt[100] = 27101;
	cnt[101] = 27097;
	cnt[102] = 27178;
	cnt[103] = 27021;
	cnt[104] = 27107;
	cnt[105] = 27013;
	cnt[106] = 26975;
	cnt[107] = 27086;
	cnt[108] = 27143;
	cnt[109] = 27133;
	cnt[110] = 26917;
	cnt[111] = 27074;
	cnt[112] = 26976;
	cnt[113] = 26792;
	cnt[114] = 26905;
	cnt[115] = 26928;
	cnt[116] = 26827;
	cnt[117] = 26892;
	cnt[118] = 26881;
	cnt[119] = 26925;
	cnt[120] = 26796;
	cnt[121] = 26823;
	cnt[122] = 26879;
	cnt[123] = 26934;
	cnt[124] = 26831;
	cnt[125] = 26788;
	cnt[126] = 26788;
	cnt[127] = 26857;
	cnt[128] = 26912;
	cnt[129] = 26781;
	cnt[130] = 26706;
	cnt[131] = 26816;
	cnt[132] = 26714;
	cnt[133] = 26709;
	cnt[134] = 26784;
	cnt[135] = 26590;
	cnt[136] = 26671;
	cnt[137] = 26605;
	cnt[138] = 26625;
	cnt[139] = 26836;
	cnt[140] = 26539;
	cnt[141] = 26668;
	cnt[142] = 26606;
	cnt[143] = 26717;
	cnt[144] = 26639;
	cnt[145] = 26632;
	cnt[146] = 26642;
	cnt[147] = 26559;
	cnt[148] = 26499;
	cnt[149] = 26563;
	cnt[150] = 26417;
	cnt[151] = 26555;
	cnt[152] = 26338;
	cnt[153] = 26617;
	cnt[154] = 26477;
	cnt[155] = 26456;
	cnt[156] = 26642;
	cnt[157] = 26415;
	cnt[158] = 26339;
	cnt[159] = 26483;
	cnt[160] = 26470;
	cnt[161] = 26399;
	cnt[162] = 26468;
	cnt[163] = 26593;
	cnt[164] = 26352;
	cnt[165] = 26354;
	cnt[166] = 26345;
	cnt[167] = 26398;
	cnt[168] = 26378;
	cnt[169] = 26469;
	cnt[170] = 26346;
	cnt[171] = 26372;
	cnt[172] = 26390;
	cnt[173] = 26434;
	cnt[174] = 26306;
	cnt[175] = 26359;
	cnt[176] = 26331;
	cnt[177] = 26390;
	cnt[178] = 26348;
	cnt[179] = 26469;
	cnt[180] = 26168;
	cnt[181] = 26342;
	cnt[182] = 26128;
	cnt[183] = 26258;
	cnt[184] = 26390;
	cnt[185] = 26251;
	cnt[186] = 26268;
	cnt[187] = 26241;
	cnt[188] = 26223;
	cnt[189] = 26395;
	cnt[190] = 25941;
	cnt[191] = 26110;
	cnt[192] = 26293;
	cnt[193] = 26226;
	cnt[194] = 26247;
	cnt[195] = 26183;
	cnt[196] = 26099;
	cnt[197] = 26034;
	cnt[198] = 26139;
	cnt[199] = 26190;
	cnt[200] = 26168;
	cnt[201] = 26268;
	cnt[202] = 26107;
	cnt[203] = 26223;
	cnt[204] = 26137;
	cnt[205] = 26001;
	cnt[206] = 26145;
	cnt[207] = 26052;
	cnt[208] = 25999;
	cnt[209] = 26168;
	cnt[210] = 26038;
	cnt[211] = 26225;
	cnt[212] = 26168;
	cnt[213] = 26057;
	cnt[214] = 26095;
	cnt[215] = 26173;
	cnt[216] = 26094;
	cnt[217] = 25948;
	cnt[218] = 25966;
	cnt[219] = 25999;
	cnt[220] = 25994;
	cnt[221] = 26045;
	cnt[222] = 26114;
	cnt[223] = 25971;
	cnt[224] = 26158;
	cnt[225] = 25913;
	cnt[226] = 26090;
	cnt[227] = 25813;
	cnt[228] = 25930;
	cnt[229] = 25903;
	cnt[230] = 25956;
	cnt[231] = 26020;
	cnt[232] = 26001;
	cnt[233] = 25825;
	cnt[234] = 25939;
	cnt[235] = 25950;
	cnt[236] = 26045;
	cnt[237] = 25925;
	cnt[238] = 26008;
	cnt[239] = 25808;
	cnt[240] = 26013;
	cnt[241] = 25938;
	cnt[242] = 25712;
	cnt[243] = 25883;
	cnt[244] = 25989;
	cnt[245] = 25900;
	cnt[246] = 25794;
	cnt[247] = 25760;
	cnt[248] = 25943;
	cnt[249] = 25783;
	cnt[250] = 25953;
	cnt[251] = 25667;
	cnt[252] = 25756;
	cnt[253] = 25915;
	cnt[254] = 25963;
	cnt[255] = 25824;
	cnt[256] = 25858;
	cnt[257] = 25833;
	cnt[258] = 25905;
	cnt[259] = 25729;
	cnt[260] = 25951;
	cnt[261] = 25770;
	cnt[262] = 25971;
	cnt[263] = 25767;
	cnt[264] = 25859;
	cnt[265] = 25928;
	cnt[266] = 25627;
	cnt[267] = 25767;
	cnt[268] = 25863;
	cnt[269] = 25623;
	cnt[270] = 25772;
	cnt[271] = 25706;
	cnt[272] = 25657;
	cnt[273] = 25806;
	cnt[274] = 25819;
	cnt[275] = 25724;
	cnt[276] = 25712;
	cnt[277] = 25735;
	cnt[278] = 25587;
	cnt[279] = 25726;
	cnt[280] = 25606;
	cnt[281] = 25780;
	cnt[282] = 25597;
	cnt[283] = 25743;
	cnt[284] = 25704;
	cnt[285] = 25615;
	cnt[286] = 25592;
	cnt[287] = 25770;
	cnt[288] = 25735;
	cnt[289] = 25588;
	cnt[290] = 25755;
	cnt[291] = 25680;
	cnt[292] = 25519;
	cnt[293] = 25692;
	cnt[294] = 25737;
	cnt[295] = 25552;
	cnt[296] = 25616;
	cnt[297] = 25639;
	cnt[298] = 25521;
	cnt[299] = 25530;
	cnt[300] = 0;
}

char is_p[D];
vi p;

void erat_0() {
	for(int i = 2; i * i < D; i++) {
		if (!is_p[i]) {
			for(int j = i * i; j < D; j += i) {
				is_p[j] = 1;
			}
		}
	}
	REP(i, 2, D) {
		if (!is_p[i]) {
			p.pb(i);
		}
	}
}

char is_p_1[D];

void erat(int l) {
	REP(i, 0, D) {
		is_p_1[i] = 0;
	}
	REP(i, 0, SZ(p)) {
		int v = p[i];
		for(int j = ((l + v - 1) / v * v) % D; j < D; j += v) {
			is_p_1[j] = 1;
		}
	}
}

int get(int n) {
	int ans = 0;
	REP(i, 0, n / D) {
		ans += cnt[i];
	}
	if (n / D == 0) {
		REPN(i, 2, n) {
			if (i % 4 != 3) {
				ans += (1 - is_p[i]);
			}
		}
	} else {
		erat(n / D * D);
		REPN(i, 0, n % D) {
			if (i % 4 != 3) {
				ans += (1 - is_p_1[i]);
			}
		}
	}
	// printf("%d: %d\n", n, ans);
	return ans;
}

void solve(){
	init();
	erat_0();
	int l, r;
	scanf("%d%d", &l, &r);
	int ans = get(r) - get(l - 1);
	printf("%d\n", ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}